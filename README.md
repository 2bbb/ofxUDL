# ofxUDL

## Usage

```cpp
#include "ofxUDL.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup() {
        using namespace ofxUDL;
        
        auto image = "hoge.jpg"_i;        // load ofImage
        auto video_player = "hoge.mp4"_v; // load ofVideoPlayer
        auto audio_player = "hoge.mp3"_a; // load ofSoundPlayer
        auto shader = "shaders/hoge"_s;   // load ofShader
        auto mesh = "mesh.ply"_m;        // load ofMesh
        
        auto json = "hoge.json"_j;        // load ofJson
        auto xml = "hoge.xml"_x;          // load ofXml
    }
};
```

## License

* MIT

## Author

* ISHII 2bit [ISHII Tsuubito Program Office, HagukiWoKamuToRingoKaraTiGaDeru]
* i[at]2bit.jp
