/*
 *  Copyright 2011, 2012, DFKI GmbH Robotics Innovation Center
 *
 *  This file is part of the MARS simulation framework.
 *
 *  MARS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3
 *  of the License, or (at your option) any later version.
 *
 *  MARS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with MARS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MARS_GRAPHICS_GL_NORMAL_MAPPING_H
#define MARS_GRAPHICS_GL_NORMAL_MAPPING_H

#include "shader-function.h"
#include "GraphicsManager.h"

#include <mars/interfaces/LightData.h>

#include <vector>
#include <string>

namespace mars {
  namespace graphics {

    class BumpMapFrag : public ShaderFunc {
    public:
      BumpMapFrag(std::vector<std::string> &args);
      std::string code() const;
    }; // end of class BumpMapFrag

    class BumpMapVert : public ShaderFunc {
    public:
      BumpMapVert(std::vector<std::string> &args,
                  std::vector<mars::interfaces::LightData*> &lightList);
      std::string code() const;
    private:
      std::vector<mars::interfaces::LightData*> lightList;
    }; // end of class BumpMapVert

  } // end of namespace graphics
} //end of namespace mars

#endif /* MARS_GRAPHICS_GL_NORMAL_MAPPING_H */

