/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_SVGAnimationElementBinding_h__
#define mozilla_dom_SVGAnimationElementBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {
namespace dom {

class SVGAnimationElement;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::SVGAnimationElement>
{
  enum
  {
    Depth = 4
  };
  typedef mozilla::dom::SVGAnimationElement NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::SVGAnimationElement>
{
  enum
  {
    PrototypeID = prototypes::id::SVGAnimationElement
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

namespace SVGAnimationElementBinding {

  extern const NativePropertyHooks sNativePropertyHooks;

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Heap<JSObject*>* protoAndIfaceArray);

  inline JS::Handle<JSObject*> GetProtoObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface prototype object for this class.  This will create the
       object as needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JS::Heap<JSObject*>* protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[prototypes::id::SVGAnimationElement]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[prototypes::id::SVGAnimationElement].address());
  }

  inline JS::Handle<JSObject*> GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface object for this class.  This will create the object as
       needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JS::Heap<JSObject*>* protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[constructors::id::SVGAnimationElement]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[constructors::id::SVGAnimationElement].address());
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

} // namespace SVGAnimationElementBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_SVGAnimationElementBinding_h__