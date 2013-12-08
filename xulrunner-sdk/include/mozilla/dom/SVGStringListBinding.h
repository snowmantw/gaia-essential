/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_SVGStringListBinding_h__
#define mozilla_dom_SVGStringListBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

namespace mozilla {

class DOMSVGStringList;

} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::SVGStringList>
{
  enum
  {
    Depth = 0
  };
  typedef mozilla::DOMSVGStringList NativeType;
};
template <>
struct PrototypeIDMap<mozilla::DOMSVGStringList>
{
  enum
  {
    PrototypeID = prototypes::id::SVGStringList
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

namespace SVGStringListBinding {

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
    if (!protoAndIfaceArray[prototypes::id::SVGStringList]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[prototypes::id::SVGStringList].address());
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
    if (!protoAndIfaceArray[constructors::id::SVGStringList]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[constructors::id::SVGStringList].address());
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  extern const DOMClass Class;

  class DOMProxyHandler : public mozilla::dom::DOMProxyHandler
  {
    inline DOMProxyHandler();

  public:
    bool
    getOwnPropertyDescriptor(JSContext* cx, JS::Handle<JSObject*> proxy, JS::Handle<jsid> id, JSPropertyDescriptor* desc, unsigned flags);

    bool
    getOwnPropertyNames(JSContext* cx, JS::Handle<JSObject*> proxy, JS::AutoIdVector& props);

    bool
    hasOwn(JSContext* cx, JS::Handle<JSObject*> proxy, JS::Handle<jsid> id, bool* bp);

    bool
    get(JSContext* cx, JS::Handle<JSObject*> proxy, JS::Handle<JSObject*> receiver, JS::Handle<jsid> id, JS::MutableHandle<JS::Value> vp);

    virtual const char*
    className(JSContext* cx, JS::Handle<JSObject*> proxy) MOZ_OVERRIDE;

    bool
    finalizeInBackground(JS::Value priv);

    void
    finalize(JSFreeOp* fop, JSObject* proxy);

    bool
    getElementIfPresent(JSContext* cx, JS::Handle<JSObject*> proxy, JS::Handle<JSObject*> receiver, uint32_t index, JS::MutableHandle<JS::Value> vp, bool* present);

    static DOMProxyHandler*
    getInstance();

    bool
    delete_(JSContext* cx, JS::Handle<JSObject*> proxy, JS::Handle<jsid> id, bool* bp);
  };

  bool
  Is(JSObject* obj);

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, mozilla::DOMSVGStringList* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace SVGStringListBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_SVGStringListBinding_h__
