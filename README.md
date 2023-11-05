# ofxUDL

## Usage

```cpp
#include "ofxUDL.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup() {
        using namespace ofxUDL;
        
        // using namespace ofxUDL::image;
        auto image = "hoge.jpg"_i;        // load ofImage

        auto video_player = "hoge.mp4"_v; // load ofVideoPlayer

        // using namespace ofxUDL::video;
        auto audio_player = "hoge.mp3"_a; // load ofSoundPlayer

        // using namespace ofxUDL::shader;
        auto shader = "shaders/hoge"_s;   // load ofShader

        // using namespace ofxUDL::mesh;
        auto mesh = "mesh.ply"_m;         // load ofMesh
        
        // using namespace ofxUDL::json;
        auto json = "hoge.json"_j;        // load ofJson

        // using namespace ofxUDL::xml;
        auto xml = "hoge.xml"_x;          // load ofXml

        // using namespace ofxUDL::file;
        auto file = "hoge.bin"_f;         // ofFile("hoge.bin")

        // using namespace ofxUDL::dir;
        auto dir = "images"_d;            // ofDirectory("images")

        // using namespace ofxUDL::buffer;
        auto buf = "1234"_b;              // ofBuffer("1234", 4)
        auto buf_file = "hoge.bin"_bf;    // ofBufferFromFile("hoge.bin")

        // using namespace ofxUDL::color;
        auto c = 100_c;                   // ofColor(100)
        auto fc = 0.5_c;                  // ofFloatColor(0.5f)

        // using namespace ofxUDL::vector;
        auto v2 = 0.0_v2;                 // glm::vec2(0.0f)
        auto iv2 = 100_v2;                 // glm::ivec2(100)
        auto rand = 2.0_r;　　　　　　　　　　// ofRandom(0.0, 2.0)

        // using namespace ofxUDL::range;
        for(auto i : 5_range) {
            ofLogNotice() << i;           // 0 1 2 3 4
        }
        for(auto i : 2, 5_range) {
            ofLogNotice() << i;           // 2 3 4
        }
        for(auto i : 2, 10_range, 2) {
            ofLogNotice() << i;           // 2 4 6 8
        }
    }
};
```

## License

* MIT

## Author

* ISHII 2bit [ISHII Tsuubito Program Office, HagukiWoKamuToRingoKaraTiGaDeru]
* i[at]2bit.jp
