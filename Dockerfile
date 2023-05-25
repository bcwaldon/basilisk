FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && apt install -y build-essential python3 python3-setuptools python3-dev python3-tk python3-pip swig

RUN pip3 install wheel "conan>=1.40.1, <=1.59.0" cmake

ADD . /usr/lib/basilisk
WORKDIR /usr/lib/basilisk

RUN python3 conanfile.py

WORKDIR /workspace
