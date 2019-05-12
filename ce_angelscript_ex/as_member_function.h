#ifndef AS_MEMBER_FUNCTION_H
#define AS_MEMBER_FUNCTION_H
#include "as_doc.h"
#include "as_parameter.h"
#include "as_return.h"

// as_member_function is a member function of a class
class as_member_function : public as_doc {
public:
   as_member_function(cf_syslib::xml_node& node);
   as_member_function(const std::string& signature, const std::string& name, bool verified, std::shared_ptr<as_description> descr = 0);
   virtual ~as_member_function();

   // find a parameter by index (may return 0)
   std::shared_ptr<as_parameter> lookup_parameter(size_t index);
   std::shared_ptr<as_return>    lookup_return() { return m_return; }

   // key returns the signature string, but with all white space removed
   std::string key() const;

   // return number of parameters
   size_t size() const { return m_params.size(); }

   // compute key from signature
   static std::string key(const std::string& signature);

   void add_parameter(std::shared_ptr<as_parameter> param);
   void add_return(std::shared_ptr<as_return> param);


   cf_syslib::xml_node to_xml(cf_syslib::xml_node& xml_parent);

   void unverify();

private:
   std::string                                m_signature;  // angelscript signature as returned by asIScriptFunction::GetDeclaration
   std::string                                m_name;       // angelscript name returned by asIScriptFunction::GetName
   std::vector<std::shared_ptr<as_parameter>> m_params;
   std::shared_ptr<as_return>                 m_return;
};

#endif // AS_MEMBER_FUNCTION_H
