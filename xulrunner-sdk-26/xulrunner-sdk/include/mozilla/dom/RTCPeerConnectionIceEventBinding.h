/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_RTCPeerConnectionIceEventBinding_h__
#define mozilla_dom_RTCPeerConnectionIceEventBinding_h__

#include "EventBinding.h"
#include "RTCIceCandidateBinding.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"
#include "nsDOMEvent.h"

namespace mozilla {
namespace dom {

class RTCPeerConnectionIceEvent;
struct RTCPeerConnectionIceEventInit;
class mozRTCIceCandidate;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::RTCPeerConnectionIceEvent>
{
  enum
  {
    Depth = 1
  };
  typedef mozilla::dom::RTCPeerConnectionIceEvent NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::RTCPeerConnectionIceEvent>
{
  enum
  {
    PrototypeID = prototypes::id::RTCPeerConnectionIceEvent
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

struct RTCPeerConnectionIceEventInit : public EventInit
{
  nsRefPtr<mozilla::dom::mozRTCIceCandidate> mCandidate;

private:
  static bool initedIds;
  static jsid candidate_id;

  RTCPeerConnectionIceEventInit(const RTCPeerConnectionIceEventInit&) MOZ_DELETE;

public:
  inline RTCPeerConnectionIceEventInit()
  {
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value");

  bool
  Init(const nsAString& aJSON);

  bool
  ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceDictionary(JSTracer* trc);

private:
  static bool
  InitIds(JSContext* cx);
};
struct RTCPeerConnectionIceEventInitInitializer : public RTCPeerConnectionIceEventInit
{
  inline RTCPeerConnectionIceEventInitInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


namespace RTCPeerConnectionIceEventBinding {

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
    if (!protoAndIfaceArray[prototypes::id::RTCPeerConnectionIceEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[prototypes::id::RTCPeerConnectionIceEvent].address());
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
    if (!protoAndIfaceArray[constructors::id::RTCPeerConnectionIceEvent]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[constructors::id::RTCPeerConnectionIceEvent].address());
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  bool
  ConstructorEnabled(JSContext* /* unused */, JS::Handle<JSObject*> /* unused */);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, mozilla::dom::RTCPeerConnectionIceEvent* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace RTCPeerConnectionIceEventBinding



class RTCPeerConnectionIceEventJSImpl : public CallbackInterface
{
public:
  explicit inline RTCPeerConnectionIceEventJSImpl(JSObject* aCallback)
    : CallbackInterface(aCallback)
  {
  }

  void __Init(const nsAString& type, const RTCPeerConnectionIceEventInit& eventInitDict, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  already_AddRefed<mozRTCIceCandidate> GetCandidate(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);
};


class RTCPeerConnectionIceEvent MOZ_FINAL : public nsDOMEvent
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(RTCPeerConnectionIceEvent, nsDOMEvent)

private:
  nsRefPtr<RTCPeerConnectionIceEventJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  RTCPeerConnectionIceEvent(JS::Handle<JSObject*> aJSImplObject, nsPIDOMWindow* aParent);

  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aScope) MOZ_OVERRIDE;

  static already_AddRefed<RTCPeerConnectionIceEvent> Constructor(const GlobalObject& global, JSContext* cx, const nsAString& type, const RTCPeerConnectionIceEventInit& eventInitDict, ErrorResult& aRv);

  // Mark this as resultNotAddRefed to return raw pointers
  already_AddRefed<mozRTCIceCandidate> GetCandidate(ErrorResult& aRv) const;

  static JSBool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_RTCPeerConnectionIceEventBinding_h__