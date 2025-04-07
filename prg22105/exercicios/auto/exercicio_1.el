;; -*- lexical-binding: t; -*-

(TeX-add-style-hook
 "exercicio_1"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "a4paper" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("babel" "brazil") ("amsmath" "") ("geometry" "") ("helvet" "") ("listings" "") ("xcolor" "")))
   (add-to-list 'LaTeX-verbatim-environments-local "lstlisting")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "lstinline")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "lstinline")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "inputenc"
    "babel"
    "amsmath"
    "geometry"
    "helvet"
    "listings"
    "xcolor")
   (LaTeX-add-xcolor-definecolors
    "codegray"
    "codeblue"
    "codered"))
 :latex)

