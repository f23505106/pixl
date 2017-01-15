//
// Copyright (c) 2016. See AUTHORS file.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef PIXL_IMAGE_H
#define PIXL_IMAGE_H

#include "types.h"

namespace pixl {

    class Image {
    public:
        Image(i32 width, i32 height, i32 channels, u8* data);
        ~Image();
        inline u8* getData() { return this->data; }
        inline i32 getWidth() { return this->width; }
        inline i32 getHeight() { return this->height; }
        inline i32 getChannels() { return this->channels; }

    private:
        i32 width;
        i32 height;
        i32 channels;
        u8* data;
    };
}

#endif