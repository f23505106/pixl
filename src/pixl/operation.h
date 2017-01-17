//
// Copyright (c) 2017. See AUTHORS file.
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

#ifndef PIXL_TRANSFORM_H
#define PIXL_TRANSFORM_H

#include <vector>
#include "image.h"

namespace pixl {

    // Performes an operation on an image
    //
    // An operation performes a transformation on the image. A transfrmation can be modify
    // the image in an arbitrary way (e.g. resizing, cropping, change saturation/brightness/contrast etc.) 
    class Operation {
    public:
        Operation() {}

        // Applies the operation to the image
        virtual void apply(Image* image) = 0;
    };


    // Allows operations to be chained.
    //
    // Chained operations will be executed in a row, one after the other.
    class OperationChain : public Operation {
    public:
        OperationChain() {}
        // Adds new operation to the end of the chain.
        void add(Operation* o) { ops.push_back(o); }

        // Removes all operations from the chain.
        void clear() { ops.clear(); }

        // Applies added operations.
        void apply(Image* image) {
            for(auto o : ops) {
                o->apply(image);
            }
        } 
    private:
        std::vector<Operation*> ops;
    };


    class FlipTransformation : public Operation {
    public:
        void apply(Image* image);
        bool horizontal;
    };
}

#endif