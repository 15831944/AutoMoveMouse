

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for AutoMoveMouse.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __AutoMoveMouse_h_h__
#define __AutoMoveMouse_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAutoMoveMouse_FWD_DEFINED__
#define __IAutoMoveMouse_FWD_DEFINED__
typedef interface IAutoMoveMouse IAutoMoveMouse;

#endif 	/* __IAutoMoveMouse_FWD_DEFINED__ */


#ifndef __AutoMoveMouse_FWD_DEFINED__
#define __AutoMoveMouse_FWD_DEFINED__

#ifdef __cplusplus
typedef class AutoMoveMouse AutoMoveMouse;
#else
typedef struct AutoMoveMouse AutoMoveMouse;
#endif /* __cplusplus */

#endif 	/* __AutoMoveMouse_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AutoMoveMouse_LIBRARY_DEFINED__
#define __AutoMoveMouse_LIBRARY_DEFINED__

/* library AutoMoveMouse */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AutoMoveMouse;

#ifndef __IAutoMoveMouse_DISPINTERFACE_DEFINED__
#define __IAutoMoveMouse_DISPINTERFACE_DEFINED__

/* dispinterface IAutoMoveMouse */
/* [uuid] */ 


EXTERN_C const IID DIID_IAutoMoveMouse;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("33252f45-046f-437c-8ec6-f7e7d46cdb0c")
    IAutoMoveMouse : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoMoveMouseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoMoveMouse * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoMoveMouse * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoMoveMouse * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoMoveMouse * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoMoveMouse * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoMoveMouse * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoMoveMouse * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IAutoMoveMouseVtbl;

    interface IAutoMoveMouse
    {
        CONST_VTBL struct IAutoMoveMouseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoMoveMouse_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoMoveMouse_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoMoveMouse_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoMoveMouse_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoMoveMouse_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoMoveMouse_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoMoveMouse_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoMoveMouse_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AutoMoveMouse;

#ifdef __cplusplus

class DECLSPEC_UUID("8466947c-e1b9-423c-9eb2-9a9545fef3b9")
AutoMoveMouse;
#endif
#endif /* __AutoMoveMouse_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


