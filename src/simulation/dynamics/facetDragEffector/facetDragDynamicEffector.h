/*
 ISC License

 Copyright (c) 2016-2018, Autonomous Vehicle Systems Lab, University of Colorado at Boulder

 Permission to use, copy, modify, and/or distribute this software for any
 purpose with or without fee is hereby granted, provided that the above
 copyright notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

 */


#ifndef FACET_DRAG_DYNAMIC_EFFECTOR_H
#define FACET_DRAG_DYNAMIC_EFFECTOR_H

#include <Eigen/Dense>
#include <vector>
#include "../_GeneralModuleFiles/dynamicEffector.h"
#include "../_GeneralModuleFiles/stateData.h"
#include "_GeneralModuleFiles/sys_model.h"
#include "../../simMessages/atmoPropsSimMsg.h"
#include "../dragEffector/dragDynamicEffector.h"
#include "../../utilities/rigidBodyKinematics.h"




/*! \addtogroup SimModelGroup
 * @{
 */


typedef struct {
  std::vector<double> facetAreas;
  std::vector<double> facetCoeffs;
  std::vector<Eigen::Vector3d> facetNormals_B;
  std::vector<Eigen::Vector3d> facetLocations_B;
}SpacecraftGeometryData;

//! @brief Drag dynamics class used to compute drag effects on spacecraft bodies
/*! This class is used to implement drag dynamic effects on spacecraft using a variety of simple or complex models, which will include
cannonball (attitude-independent) drag, single flat-plate drag, faceted drag models, and an interface to full-CAD GPU-accellerated
drag models. */

class FacetDragDynamicEffector: public SysModel, public DynamicEffector {
public:


    FacetDragDynamicEffector();
    ~FacetDragDynamicEffector();
    void linkInStates(DynParamManager& states);
    void computeForceTorque(double integTime);
    void SelfInit();
    void CrossInit();
    void Reset(uint64_t CurrentSimNanos);
    void UpdateState(uint64_t CurrentSimNanos);
    void WriteOutputMessages(uint64_t CurrentClock);
    bool ReadInputs();
    void setDensityMessage(std::string newDensMessage);
    void addFacet(double area, double dragCoeff, Eigen::Vector3d B_normal_hat, Eigen::Vector3d B_location);

private:

    void plateDrag();
    void updateDragDir();
public:
    uint64_t numFacets;
    std::string atmoDensInMsgName;                  //!< -- message used to read command inputs
    std::string navAttInMsgName;                    //!< -- message used to read command inputs
    StateData *hubSigma;                            //!< -- Hub/Inertial attitude represented by MRP
    StateData *hubVelocity;                         //!< m/s Hub inertial velocity vector
    Eigen::Vector3d v_B;                            //!< m/s local variable to hold the inertial velocity
    Eigen::Vector3d v_hat_B;

private:
    int64_t densInMsgId;                            //!< -- Message ID for incoming data
    AtmoPropsSimMsg atmoInData;
    SpacecraftGeometryData scGeometry;              //!< -- Struct to hold spacecraft facet data

};

#endif 