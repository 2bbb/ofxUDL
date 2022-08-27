//
//  ofxUDL.h
//
//  Created by 2bit on 2022/08/28.
//

#ifndef ofxUDL_h
#define ofxUDL_h

#include "ofImage.h"
#include "ofVideoPlayer.h"
#include "ofSoundPlayer.h"
#include "ofMesh.h"
#include "ofShader.h"

#include "ofJson.h"
#include "ofXml.h"

namespace ofx {
    namespace UserDefinedLiterals {
        ofImage operator"" _i(const char* str, std::size_t length) {
            return ofImage{std::string{str}};
        }
        
        ofVideoPlayer operator"" _v(const char* str, std::size_t length) {
            ofVideoPlayer player;
            player.load(std::string{str});
            return std::move(player);
        }
        
        ofSoundPlayer operator"" _a(const char* str, std::size_t length) {
            ofSoundPlayer player;
            player.load(std::string{str});
            return std::move(player);
        }
        
        ofMesh operator"" _m(const char* str, std::size_t length) {
            ofMesh mesh;
            mesh.load(std::string{str});
            return std::move(mesh);
        }
        
        ofShader operator"" _s(const char* str, std::size_t length) {
            ofShader shader;
            shader.load(std::string{str});
            return std::move(shader);
        }
        
        ofJson operator"" _j(const char* str, std::size_t length) {
            return ofLoadJson(std::string{str});
        }
        
        ofXml operator"" _x(const char* str, std::size_t length) {
            ofXml xml;
            xml.load(std::string{str});
            return std::move(xml);
        }
    };
};

namespace ofxUserDefinedLiterals = ofx::UserDefinedLiterals;
namespace ofxUDL = ofx::UserDefinedLiterals;

#endif /* ofxUDL_h */
