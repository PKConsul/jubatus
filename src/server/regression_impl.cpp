// this program is automatically generated by jenerator. do not edit.
#include "../framework.hpp"
#include "regression_server.hpp"
#include "regression_serv.hpp"
using namespace jubatus;
using namespace jubatus::framework;
namespace jubatus { namespace server {
class regression_impl_ : public regression<regression_impl_>
{
public:
  regression_impl_(const server_argv& a):
    regression<regression_impl_>(a.timeout),
    p_(new regression_serv(a))
  {}

  bool set_config(std::string name, config_data c) //update broadcast
  { JWLOCK__(p_); return p_->set_config(c); }

  config_data get_config(std::string name) //analysis random
  { JRLOCK__(p_); return p_->get_config(); }

  int train(std::string name, std::vector<std::pair<float,datum > > train_data) //update random
  { JWLOCK__(p_); return p_->train(train_data); }

  std::vector<float > estimate(std::string name, std::vector<datum > estimate_data) //analysis random
  { JRLOCK__(p_); return p_->estimate(estimate_data); }

  bool save(std::string name, std::string arg1) //update broadcast
  { JWLOCK__(p_); return p_->save(arg1); }

  bool load(std::string name, std::string arg1) //update broadcast
  { JWLOCK__(p_); return p_->load(arg1); }

  std::map<std::string,std::map<std::string,std::string > > get_status(std::string name) //analysis broadcast
  { JRLOCK__(p_); return p_->get_status(); }
  int run(){ return p_->start(*this); };
  common::cshared_ptr<regression_serv> get_p(){ return p_; };
private:
  common::cshared_ptr<regression_serv> p_;
};
}} // namespace jubatus::server
int main(int args, char** argv){
  return
    jubatus::framework::run_server<jubatus::server::regression_impl_,
                                   jubatus::server::regression_serv>
       (args, argv);
}
