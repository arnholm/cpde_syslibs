#include "as_constructor.h"
#include "as_xml.h"

as_constructor::as_constructor(const std::string& signature, bool verified,  std::shared_ptr<as_description> descr)
: as_doc(verified,descr)
, m_signature(signature)
{}

as_constructor::as_constructor(cf_syslib::xml_node& node)
: as_doc(node)
{
   m_signature = node.get_property("signature","as_error");
   for(auto i=node.begin(); i!=node.end(); i++) {
      cf_syslib::xml_node sub(i);
      if(!sub.is_attribute_node()) {
         if(sub.tag() == "as_parameter") m_params.push_back(std::make_shared<as_parameter>(sub));
      }
   }
}

as_constructor::~as_constructor()
{}

void as_constructor::add_parameter(std::shared_ptr<as_parameter> param)
{
   m_params.push_back(param);
}

std::string as_constructor::key(size_t istart, const std::string& signature)
{
   std::string key_sig;
   std::vector<std::string> tokens;
   as_description::tokenize(signature," ",tokens);

   // skip the 1st token, the return type
   for(size_t i=istart;i<tokens.size();i++) {
      key_sig+=tokens[i];
   }
   return key_sig;
}

std::string as_constructor::key() const
{
   return key(1,m_signature);
}


cf_syslib::xml_node as_constructor::to_xml(cf_syslib::xml_node& xml_parent)
{
   cf_syslib::xml_node xml_this = xml_parent.add_child(as_typeid(this));
   as_doc::to_xml(xml_this);

   xml_this.add_property("signature",m_signature);
   for(auto& par : m_params) {
      par->to_xml(xml_this);
   }

   return xml_this;
}

std::shared_ptr<as_parameter> as_constructor::lookup_parameter(size_t index)
{
   std::shared_ptr<as_parameter> par;
   if(index < m_params.size()) par = m_params[index];
   return par;
}

void as_constructor::unverify()
{
   set_verified(false);
   for(auto& par : m_params) {
      par->unverify();
   }
}

void as_constructor::write_header(std::ostream& hfile)
{
   if(auto descr = description())  descr->write_header(hfile);

   std::vector<std::string> lines;
   for(auto& par : m_params) {
      lines.push_back(par->doxy_string());
   }

   if(lines.size() > 0) {
      size_t last_line = lines.size()-1;
      for(size_t i=0; i<lines.size(); i++) {
         if(i==        0) hfile << "   /*! " << lines[i];
         else             hfile << "   \\n " << lines[i];
         if(i==last_line) hfile << " */";
         hfile << std::endl;
      }
   }
   size_t ipos = m_signature.find(' ');
   hfile << "  " << as_xml::fix_array_types(m_signature.substr(ipos)) << ';' << std::endl << std::endl;
}


void as_constructor::add_xml_todo(as_xml* factory, size_t level)
{
   if(level==2) {
      auto descr = description();
      if(!descr.get()) {
         set_description(std::make_shared<as_description>("XML_TODO"));
      }
   }
   if(level > 2) {
      for(auto p : m_params) p->add_xml_todo(factory,level);
   }
}
