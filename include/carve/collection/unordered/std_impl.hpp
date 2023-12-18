// Begin License:
// Copyright (C) 2006-2011 Tobias Sargeant (tobias.sargeant@gmail.com).
// All rights reserved.
//
// This file is part of the Carve CSG Library (http://carve-csg.com/)
//
// This file may be used under the terms of the GNU General Public
// License version 2.0 as published by the Free Software Foundation
// and appearing in the file LICENSE.GPL2 included in the packaging of
// this file.
//
// This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
// INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE.
// End:


#pragma once

#include <unordered_map>
#include <unordered_set>

namespace std {
  template <typename A, typename B>
  struct hash<std::pair<A, B> > : public std::unary_function<std::pair<A, B>, size_t> {
    size_t operator()(const std::pair<A, B> &v) const {
      std::size_t seed = 0;

      seed ^= hash<A>()(v.first);
      seed ^= hash<B>()(v.second) + (seed<<6) + (seed>>2);

      return seed;
    }
  };
}

#undef UNORDERED_COLLECTIONS_SUPPORT_RESIZE
