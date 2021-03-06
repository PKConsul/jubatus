// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#pragma once

#include <pficommon/data/serialization.h>
#include <pficommon/data/serialization/unordered_map.h>
#include <pficommon/data/intern.h>
#include "local_storage.hpp"

namespace jubatus {
namespace storage {

class local_storage_mixture : public storage_base
{
public:
  local_storage_mixture();
  ~local_storage_mixture();

  void get(const std::string &feature, feature_val1_t& ret);
  void get2(const std::string &feature, feature_val2_t& ret);
  void get3(const std::string &feature, feature_val3_t& ret);

  void inp(const sfv_t& sfv, map_feature_val1_t& ret); /// inner product 
  
  void get_diff(features3_t& ret) const;
  void set_average_and_clear_diff(const features3_t& average);

  void set(const std::string &feature, const std::string &klass, const val1_t& w);
  void set2(const std::string &feature, const std::string &klass, const val2_t& w);
  void set3(const std::string &feature, const std::string &klass, const val3_t& w);

  void get_status(std::map<std::string,std::string>&);

  void update(const std::string &feature, const std::string& inc_class, const std::string& dec_class, val1_t v);

  void bulk_update(const sfv_t& sfv, float step_width, const std::string& inc_class, const std::string& dec_class);

  bool save(std::ostream& os);
  bool load(std::istream& is);
  std::string type()const;
private:
  friend class pfi::data::serialization::access;
  template<class Ar>
  void serialize(Ar& ar) {
    ar & MEMBER(tbl_)
      & MEMBER(class2id_)
      & MEMBER(tbl_diff_);
  }

  bool get_internal(const std::string& feature, id_feature_val3_t& ret) const;

  id_features3_t tbl_;
  key_manager class2id_;
  id_features3_t tbl_diff_;
};

}
}
