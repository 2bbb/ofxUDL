//
//  ofxUDL.h
//
//  Created by 2bit on 2022/08/28.
//

#ifndef ofxUDL_h
#define ofxUDL_h

#include "ofVectorMath.h"
#include "ofColor.h"
#include "ofImage.h"
#include "ofVideoPlayer.h"
#include "ofSoundPlayer.h"
#include "ofMesh.h"
#include "ofShader.h"
#include "ofUtils.h"
#include "ofFileUtils.h"

#include "ofJson.h"
#include "ofXml.h"

namespace ofx {
    namespace UserDefinedLiterals {
        inline namespace vector {
            glm::ivec2 operator""_v2(unsigned long long v) {
                return glm::ivec2(static_cast<int>(v));
            }
            glm::vec2 operator""_v2(long double v) {
                return glm::vec2(static_cast<float>(v));
            }
            
            glm::ivec3 operator""_v3(unsigned long long v) {
                return glm::ivec3(static_cast<int>(v));
            }
            glm::vec3 operator""_v3(long double v) {
                return glm::vec3(static_cast<float>(v));
            }
            
            glm::ivec4 operator""_v4(unsigned long long v) {
                return glm::ivec4(static_cast<int>(v));
            }
            glm::vec4 operator""_v4(long double v) {
                return glm::vec4(static_cast<float>(v));
            }
        }
        
        inline namespace color {
            ofColor operator"" _c(unsigned long long c) {
                return ofColor(c, c, c, 255);
            }
            ofFloatColor operator"" _c(long double c) {
                return ofFloatColor(c, c, c, 1.0f);
            }
        }
        
        inline namespace image {
            ofImage operator"" _i(const char* str, std::size_t length) {
                return ofImage{std::string{str}};
            }
        }
        
        inline namespace video {
            ofVideoPlayer operator"" _v(const char* str, std::size_t length) {
                ofVideoPlayer player;
                player.load(std::string{str});
                return std::move(player);
            }
        }
        
        inline namespace audio {
            ofSoundPlayer operator"" _a(const char* str, std::size_t length) {
                ofSoundPlayer player;
                player.load(std::string{str});
                return std::move(player);
            }
        }
        
        inline namespace mesh {
            ofMesh operator"" _m(const char* str, std::size_t length) {
                ofMesh mesh;
                mesh.load(std::string{str});
                return std::move(mesh);
            }
        }
        
        inline namespace shader {
            ofShader operator"" _s(const char* str, std::size_t length) {
                ofShader shader;
                shader.load(std::string{str});
                return std::move(shader);
            }
        }
        
        inline namespace json {
            ofJson operator"" _j(const char* str, std::size_t length) {
                return ofLoadJson(std::string{str});
            }
        }
        
        inline namespace xml {
            ofXml operator"" _x(const char* str, std::size_t length) {
                ofXml xml;
                xml.load(std::string{str});
                return std::move(xml);
            }
        }
        
        inline namespace buffer {
            ofBuffer operator"" _b(const char* str, std::size_t length) {
                return { str, length };
            }
            ofBuffer operator"" _bf(const char* str, std::size_t length) {
                return ofBufferFromFile(std::string{str, length});
            }
        }

        inline namespace file {
            ofFile operator"" _f(const char* str, std::size_t length) {
                return { std::string{str} };
            }
        }
        
        inline namespace dir {
            ofDirectory operator"" _d(const char* str, std::size_t length) {
                return { std::string{str} };
            }
        }

        inline namespace format {
            struct VAArgsFormatter {
                std::string format;
                VAArgsFormatter(const std::string &format)
                : format{format} {};
                VAArgsFormatter(std::string &&format)
                : format{std::move(format)} {};
                
                VAArgsFormatter(const VAArgsFormatter &) = default;
                VAArgsFormatter(VAArgsFormatter &&) = default;
                
                VAArgsFormatter& operator=(const VAArgsFormatter &) = default;
                VAArgsFormatter& operator=(VAArgsFormatter &&) = default;
                
                template <typename ... arguments>
                inline std::string operator()(arguments && ... args) const {
                    return ofVAArgsToString(format.c_str(), std::forward<arguments>(args) ...);
                }
            private:
                VAArgsFormatter() = delete;
            };
            
            VAArgsFormatter operator"" _fmt(const char* format, std::size_t length) {
                return { std::string{format} };
            }
        }
        
        inline namespace random {
            float operator""_r(long double v) {
                return ofRandom(v);
            }
            float operator""_r(unsigned long long v) {
                return ofRandom(v);
            }
        }
        
        inline namespace range {
            struct range_iterator_object {
                struct iterator {
                    iterator(std::size_t index,
                             std::size_t last,
                             std::size_t offset)
                    : index{last < index ? last : index}
                    , last{last}
                    , offset{offset}
                    {};
                    
                    iterator &operator++() {
                        index += offset;
                        if(last < index) index = last;
                        return *this;
                    }
                    iterator operator++(int) {
                        auto it = iterator{ index, last, offset };
                        operator++();
                        return it;
                    }

                    bool operator!=(const iterator &rhs) const {
                        return index != rhs.index
                            || last != rhs.last
                            || offset != rhs.offset;
                    }
                    
                    std::size_t operator*() const
                    { return index; };
                private:
                    std::size_t index;
                    std::size_t last;
                    std::size_t offset;
                };
                
                constexpr range_iterator_object(std::size_t last)
                : last{last}
                {};
                
                constexpr range_iterator_object(std::size_t last,
                                                std::size_t origin)
                : last{last}
                , origin{origin}
                {};
                
                constexpr range_iterator_object(std::size_t last,
                                                std::size_t origin,
                                                std::size_t offset)
                : last{last}
                , origin{origin}
                , offset{offset}
                {};
                
                constexpr range_iterator_object(const range_iterator_object &) = default;
                
                friend
                constexpr range_iterator_object operator,(std::size_t origin,
                                                          const range_iterator_object &rio)
                { return { rio.last, origin, rio.offset }; }
                constexpr range_iterator_object operator,(std::size_t offset) const {
                    return { last, origin, offset };
                }

//                constexpr range_iterator_object operator+(std::size_t origin) const {
//                    return { last + origin, origin, offset };
//                }
//
//                friend
//                constexpr range_iterator_object operator+(std::size_t origin,
//                                                          const range_iterator_object &rio)
//                { return { rio.last + origin, origin, rio.offset }; }
//
//                constexpr range_iterator_object operator*(std::size_t offset) const {
//                    return { last, origin, offset };
//                }
//
//                friend
//                constexpr range_iterator_object operator*(std::size_t offset,
//                                                          const range_iterator_object &rio)
//                { return { rio.last, rio.origin, offset }; }
                
                iterator begin() const
                { return { origin, last, offset }; }
                iterator end() const
                { return { last, last, offset }; }

            private:
                const std::size_t last;
                const std::size_t origin{0};
                const std::size_t offset{1};
            };
            
            range_iterator_object operator""_range(unsigned long long end) {
                return { static_cast<std::size_t>(end) };
            }
        };
    };
};

namespace ofxUserDefinedLiterals = ofx::UserDefinedLiterals;
namespace ofxUDL = ofx::UserDefinedLiterals;

#endif /* ofxUDL_h */
