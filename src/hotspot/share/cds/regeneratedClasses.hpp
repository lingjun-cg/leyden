/*
 * Copyright (c) 2023, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_CDS_REGENERATEDCLASSES_HPP
#define SHARE_CDS_REGENERATEDCLASSES_HPP

#include "memory/allStatic.hpp"
#include "oops/oopHandle.hpp"
#include "utilities/growableArray.hpp"
#include "utilities/resourceHash.hpp"

class RegeneratedClasses : public AllStatic {
 private:
  using AddrToAddrTable = ResourceHashtable<address, address, 15889, AnyObj::C_HEAP, mtClassShared>;
  // These two tables contain InstanceKlass* and Method*.
  static AddrToAddrTable* _original_objs;    // regenerated object -> orig object
  static AddrToAddrTable* _renegerated_objs; // orig object        -> regenerated object
  static GrowableArrayCHeap<OopHandle, mtClassShared>* _regenerated_mirrors;
 public:
  static void add_class(InstanceKlass* src_klass, InstanceKlass* regen_klass);
  static void cleanup();
  static bool has_been_regenerated(address orig_obj);
  static address get_regenerated_object(address orig_obj);
  static bool is_a_regenerated_object(address obj);
  static void record_regenerated_objects();
};

#endif // SHARE_CDS_REGENERATEDCLASSES_HPP
