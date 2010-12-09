
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

#ifndef test_elementremoveattributenodenomodificationallowederrEE
#define test_elementremoveattributenodenomodificationallowederrEE

#include "dom_conf_test.hpp"

/**
 *     The "removeAttributeNode(oldAttr)" method for an attribute causes the 
 *    DOMException NO_MODIFICATION_ALLOWED_ERR to be raised
 *    if the node is readonly.
 *    
 *    Create an entity reference and add it to the children of the THIRD "gender" element.
 *    Try to remove the "domestic" attribute from the entity 
 *    reference by executing the "removeAttributeNode(oldAttr)" method.
 *    This causes a NO_MODIFICATION_ALLOWED_ERR DOMException to be thrown.
* @author Curt Arnold
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='NO_MODIFICATION_ALLOWED_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-258A00AF')/constant[@name='NO_MODIFICATION_ALLOWED_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D589198">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D589198</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-D589198')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='NO_MODIFICATION_ALLOWED_ERR'])">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#xpointer(id('ID-D589198')/raises/exception[@name='DOMException']/descr/p[substring-before(.,':')='NO_MODIFICATION_ALLOWED_ERR'])</a>
* @see <a href="http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D589198">http://www.w3.org/TR/1998/REC-DOM-Level-1-19981001/level-one-core#ID-D589198</a>
* @see <a href="http://www.w3.org/2001/DOM-Test-Suite/level1/core/elementremoveattributenodenomodificationallowederr.xml">http://www.w3.org/2001/DOM-Test-Suite/level1/core/elementremoveattributenodenomodificationallowederr.xml</a>
*/

template<class string_type, class string_adaptor>
class elementremoveattributenodenomodificationallowederrEE : public DOMTestCase<string_type, string_adaptor> 
{
   public: 
     elementremoveattributenodenomodificationallowederrEE(std::string name) : DOMTestCase(name)
     {

       //   check if loaded documents are supported for content type
       const std::string contentType = getContentType();
    preload(contentType, "staff", true);
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
      NodeList genderList;
      Node gender;
      EntityReference entRef;
      Element entElement;
      NamedNodeMap attrList;
      Attr attrNode;
      Attr removedAttr;
      Node appendedChild;
      doc = (Document) load("staff", true);
      genderList = doc.getElementsByTagName(SA::construct_from_utf8("gender"));
      gender = genderList.item(2);
      entRef = doc.createEntityReference(SA::construct_from_utf8("ent4"));
      assertNotNull(entRef);
      appendedChild = gender.appendChild(entRef);
      entElement = (Element) entRef.getFirstChild();
      assertNotNull(entElement);
      attrList = entElement.getAttributes();
      attrNode = (Attr) attrList.getNamedItem(SA::construct_from_utf8("domestic"));
      assertNotNull(attrNode);
      
      {
         boolean success = false;
         try {
            removedAttr = entElement.removeAttributeNode(attrNode);
          } catch (const DOMException& ex) {
            success = (ex.code() == DOMException::NO_MODIFICATION_ALLOWED_ERR);
         }
         assertTrue(success);
      }

   }
  
   /*
    *  Gets URI that identifies the test.
    */
   std::string getTargetURI() const
   {
      return "http://www.w3.org/2001/DOM-Test-Suite/level1/core/elementremoveattributenodenomodificationallowederrEE";
   }
};

#endif