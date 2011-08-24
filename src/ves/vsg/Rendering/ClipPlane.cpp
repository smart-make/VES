/*========================================================================
  VES --- VTK OpenGL ES Rendering Toolkit

      http://www.kitware.com/ves

  Copyright 2011 Kitware, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 ========================================================================*/

# include "ClipPlane.h"

#include "vsg/vsgVisitor.h"

namespace vsg {
// IMPORTANT: Make sure that this struct has no pointers.  All pointers should
// be put in the class declaration. For all newly defined pointers make sure
// to update constructor and destructor methods.
struct ClipPlaneInternal
{
  double value; // sample

};

ClipPlane::ClipPlane()
{
  _internal = new ClipPlaneInternal();
  _enabled = true;
  _plane[0] = 0;
  _plane[1] = 1;
  _plane[2] = 0;
  _plane[3] = 0;
}

ClipPlane::~ClipPlane()
{
  delete _internal;
}

bool ClipPlane::accept(vsgVisitor *vsgVisitor)
{
  return vsgVisitor->visitClipPlane(this);
}

}
