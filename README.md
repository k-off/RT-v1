# RT-v1
A simple ray tracer for mac.

![alt text](https://repository-images.githubusercontent.com/190928812/693a2280-9de5-11e9-92cd-773b96835e32)

### Shapes:
- sphere
- plane
- cone
- cylinder
- square
- disk

### Lights:
- ambient
- point
- directional

### Other:
- antialiasing
- reflections
- shadows

## Usage:

```
    clone
    cd <repository>
    make
    ./RTv1 "scene x"
```
**after a black window pops up press `enter` for full detail rendering or `p` for the fast preview**

Since the subject specifies that image has to be recalculated only only on our request, it is necessarry to press `enter` or `p` every time the camera (`k`) or an object (`o`) have been moved (`w`, `a`, `s`, `d`, `q`, `c` keys) or rotated (`arrow keys`, `right ctrl` and `num 0`).
 
### Keyboard:

```
    - enter   - render full detail (slow)
    - p       - preview (low detail, fast rendering)
    - m       - show/hide menu
    - wasd    - move object/camera, q and c for z-axis
    - arrows  - rotate objrect/camera, right-ctrl and num0 for z-axis
    - o       - switch to objects
    - tab     - switch between objects
    - k       - switch to camera
```
