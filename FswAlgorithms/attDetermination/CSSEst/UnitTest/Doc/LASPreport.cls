\NeedsTeXFormat{LaTeX2e}[1994/06/01]
\ProvidesClass{IAC}[2015/03/30 v1.0 LASP document class]
\typeout{TYPESETTING in LASP System Engineering Report...}

\LoadClass[titlepage,11pt]{article}

%
%	Load in required packages
%
\RequirePackage{graphicx}
\RequirePackage{bm}
\RequirePackage{overcite}
\RequirePackage{amssymb}
\RequirePackage{amsmath}
\RequirePackage{subfigure}
\RequirePackage{longtable}
%\RequirePackage{mathabx}
\RequirePackage{mathtools}
\RequirePackage{color}
%\RequirePackage[normalem]{ulem}
\RequirePackage{lastpage}
%\RequirePackage[original,runin]{abstract}
\RequirePackage[total={6.5in,9in},top=1in, left=1in]{geometry}
\RequirePackage[colorlinks=false,hyperfootnotes=false]{hyperref}
\RequirePackage{url}
\RequirePackage{titling}
\RequirePackage[compact]{titlesec}
\RequirePackage[margin=0pt,font=small,labelfont=bf,labelsep=colon,indention=1.5em]{caption}
%\RequirePackage{ragged2e}
\RequirePackage[perpage,ragged,hang]{footmisc}
\RequirePackage[absolute]{textpos}

\renewcommand*{\familydefault}{\sfdefault}


%
%	setup header and footers
%
\RequirePackage{fancyhdr}
\fancyhead{}
\fancyfoot{}
\fancyhead[L]{\footnotesize EMM SER-\SERnumber\\ Document No \AgileRevisionNumber}
\fancyhead[R]{\footnotesize LASP Engineering Division\\ Page \thepage \ of \pageref{LastPage}}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}



%
%	setup makeCover command
%
\newcommand{\makeCover}{

\begin{textblock*}{6.625in}(0.75in,0.975in)
	\includegraphics[width=6.625in]{coverImage.pdf}
\end{textblock*}

\begin{textblock*}{2in}(1in,10.15in)
\small \noindent Form 139399 RevA:
\end{textblock*}

\begin{textblock*}{6.5in}(1in,2.3in)
\centering
\Large\bfseries \noindent Program Partners:
\end{textblock*}

\begin{textblock*}{6.5in}(1in,3.5in)
\centering
\LARGE\bfseries \noindent Emirates Mars Mission (EMM):\\
\vskip 0.1in
\noindent System Engineering Report (SER)\\
\large\noindent SER-ADC-\SERnumber\\
\vskip 0.1in
\noindent Agile \# rev \AgileRevisionNumber\\
\vskip 0.1in
\noindent \MakeUppercase{\subject}
\end{textblock*}

~\\
\vskip 4.25in
{\renewcommand{\arraystretch}{2}
\noindent
\begin{tabular}{|p{1.6in}|p{4.7in}|}
\hline
~Prepared by & \preparer, \SubSystem\\
\hline
\end{tabular}
}
\vskip 0.2in

{\renewcommand{\arraystretch}{2}
\noindent
\begin{tabular}{|p{6.46in}|}
\hline
~{\bfseries Status:}~~ \status \\
\hline
~{\bfseries Scope/Contents} \\
\hline
\summary \\
\hline
\end{tabular}
}
\vskip 0.2in
}

%
%	setup float environment spacing
%
\setlength\textfloatsep{5pt}
\setlength{\abovecaptionskip}{3pt}
\renewcommand{\figurename}{Fig.}

%
%	cancel the date formatting
%
\date{}


%
%	Rename the Bibliography section label
%
\renewcommand{\refname}{REFERENCES}

%
%	Miscellaneous definitions
%
