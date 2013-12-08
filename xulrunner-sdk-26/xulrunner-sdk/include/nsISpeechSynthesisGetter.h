/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/base/nsISpeechSynthesisGetter.idl
 */

#ifndef __gen_nsISpeechSynthesisGetter_h__
#define __gen_nsISpeechSynthesisGetter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISpeechSynthesisGetter */
#define NS_ISPEECHSYNTHESISGETTER_IID_STR "31e6c818-0279-4948-843c-930043f6bafd"

#define NS_ISPEECHSYNTHESISGETTER_IID \
  {0x31e6c818, 0x0279, 0x4948, \
    { 0x84, 0x3c, 0x93, 0x00, 0x43, 0xf6, 0xba, 0xfd }}

class NS_NO_VTABLE nsISpeechSynthesisGetter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPEECHSYNTHESISGETTER_IID)

  /* readonly attribute nsISupports speechSynthesis; */
  NS_IMETHOD GetSpeechSynthesis(nsISupports * *aSpeechSynthesis) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeechSynthesisGetter, NS_ISPEECHSYNTHESISGETTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPEECHSYNTHESISGETTER \
  NS_IMETHOD GetSpeechSynthesis(nsISupports * *aSpeechSynthesis); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPEECHSYNTHESISGETTER(_to) \
  NS_IMETHOD GetSpeechSynthesis(nsISupports * *aSpeechSynthesis) { return _to GetSpeechSynthesis(aSpeechSynthesis); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPEECHSYNTHESISGETTER(_to) \
  NS_IMETHOD GetSpeechSynthesis(nsISupports * *aSpeechSynthesis) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeechSynthesis(aSpeechSynthesis); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeechSynthesisGetter : public nsISpeechSynthesisGetter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPEECHSYNTHESISGETTER

  nsSpeechSynthesisGetter();

private:
  ~nsSpeechSynthesisGetter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSpeechSynthesisGetter, nsISpeechSynthesisGetter)

nsSpeechSynthesisGetter::nsSpeechSynthesisGetter()
{
  /* member initializers and constructor code */
}

nsSpeechSynthesisGetter::~nsSpeechSynthesisGetter()
{
  /* destructor code */
}

/* readonly attribute nsISupports speechSynthesis; */
NS_IMETHODIMP nsSpeechSynthesisGetter::GetSpeechSynthesis(nsISupports * *aSpeechSynthesis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISpeechSynthesisGetter_h__ */
