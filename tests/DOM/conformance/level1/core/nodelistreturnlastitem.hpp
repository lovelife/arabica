
/*
This c++ source file was generated by for Arabica
and is a derived work from the source document.
The source document contained the following notice:


Copyright (c) 2001-2004 World Wide Web Consortium,
(Massachusetts Institute of Technology, Institut National de
Recherche en Informatique et en Automatique, Keio University). All
Rights Reserved. This program is distributed under the W3C's Software
Intellectual Property License. This program is distributed in the
hope that it will be useful, but WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.
See W3C License http://www.w3.org/Consortium/Legal/ for more details.

*/

#ifndef test_nodelistreturnlastitem
#define test_nodelistreturnlastitem

#include "dom_conf_test.hpp"

/**
 * Get this last child of the third employee using NodeList.item(NodeList.length - 1)
 * and check that it is either a Text element (with whitespace) or an address element.
* @author NIST
* @author Mary Brady
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-844377136">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-844377136</a>
*/

template<class string_type, class string_adaptor>
class nodelistreturnlastitem : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     nodelistreturnlastitem(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", false);
    }

  typedef typename DOMTestCase<string_type, string_adaptor> baseT;
  using baseT::DOMImplementation;
  using baseT::Document; 
  using baseT::DocumentType;
  using baseT::DocumentFragment; 
  using baseT::Node;
  using baseT::Element;
  using baseT::Attr;
  using baseT::NodeList;
  using baseT::NamedNodeMap;
  using baseT::Entity;
  using baseT::EntityReference;
  using baseT::CharacterData;
  using baseT::CDATASection;
  using baseT::Text;
  using baseT::Comment;
  using baseT::ProcessingInstruction;
  using baseT::Notation;

  typedef typename Arabica::DOM::DOMException DOMException;
  typedef string_type String;
  typedef string_adaptor SA;
  typedef bool boolean;

   /*
    * Runs the test case.
    */
   void runTest()
   {
      Document doc;
      NodeList elementList;
      Node employeeNode;
      NodeList employeeList;
      Node child;
      String childName;
      int length;
      doc = (Document) load("staff", false);
      elementList = doc.getElementsByTagName(SA::construct_from_utf8("employee"));
      employeeNode = elementList.item(2);
      employeeList = employeeNode.getChildNodes();
      length = (int) employeeList.getLength();
      
      if (equals(6, length)) {
          child = employeeList.item(5);
      childName = child.getNodeName();
      assertEquals("address", childName);
  } else {
          child = employeeList.item(12);
      childName = child.getNodeName();
      assertEquals("#text", childName);
  }
        
    
   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/nodelistreturnlastitem";
   }
};

#endif