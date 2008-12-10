(use gl)
(use gl.glut)
(use gl.simple.viewer)

(define (draw-rectangle color p1 p2 p3 p4)
  (gl-begin GL_LINE_LOOP)
  (apply gl-color color)
  (apply gl-vertex p1)
  (apply gl-vertex p2)
  (apply gl-vertex p3)
  (apply gl-vertex p4)
  (gl-end))

;; Someday, we use open-gl without the help of gache!

(load "./3d-data.scm")

(define color1  '(0.2 0.7 0.9))
(define color2  '(1.0 0.2 0.3))

(define (main args)
  (glut-init args)
  (simple-viewer-display
   (lambda ()
     (apply draw-rectangle color1 rect-before)
     (apply draw-rectangle color2 rect-after)
     (gl-flush)))
  (simple-viewer-window 'hey)
  (simple-viewer-run)
  0)
