#pragma once


namespace sockets
{


   class CLASS_DECL_APEX sip_base :
      virtual public ::object
   {
   public:

      string new_guid();
      string new_branchid();
      string new_derived_branchid(
         const ::scoped_string & scopedstrToTag,
         const ::scoped_string & scopedstrFromTag);

   };


} // namespace sockets






