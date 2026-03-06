/*
 * WebView2 embedded browser stub DLL
 *
 * Copyright 2026 Wine project
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>

#define COBJMACROS
#include "windef.h"
#include "winbase.h"
#include "objbase.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(webview2);

/*
 * Minimal COM interface declarations for WebView2 callback.
 * These match the ABI layout expected by WebView2Loader.dll.
 */

typedef struct ICoreWebView2Environment ICoreWebView2Environment;
typedef struct ICoreWebView2EnvironmentOptions ICoreWebView2EnvironmentOptions;

typedef struct ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandlerVtbl
{
    /* IUnknown */
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(void *this, REFIID riid, void **ppvObject);
    ULONG (STDMETHODCALLTYPE *AddRef)(void *this);
    ULONG (STDMETHODCALLTYPE *Release)(void *this);
    /* ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler */
    HRESULT (STDMETHODCALLTYPE *Invoke)(void *this, HRESULT errorCode, ICoreWebView2Environment *environment);
} ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandlerVtbl;

typedef struct ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler
{
    const ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandlerVtbl *lpVtbl;
} ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler;

/***********************************************************************
 *      CreateWebViewEnvironmentWithOptionsInternal (EmbeddedBrowserWebView.@)
 */
HRESULT WINAPI CreateWebViewEnvironmentWithOptionsInternal(
        UINT unk_arg1,
        PCWSTR browserExecutableFolder,
        PCWSTR userDataFolder,
        ICoreWebView2EnvironmentOptions *environmentOptions,
        ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler *environmentCreatedHandler)
{
    FIXME("(%u, %s, %s, %p, %p): stub, calling back with E_NOTIMPL\n",
          unk_arg1, debugstr_w(browserExecutableFolder), debugstr_w(userDataFolder),
          environmentOptions, environmentCreatedHandler);

    if (environmentCreatedHandler)
        return environmentCreatedHandler->lpVtbl->Invoke(environmentCreatedHandler, E_NOTIMPL, NULL);

    return E_NOTIMPL;
}

/***********************************************************************
 *      DllMain (EmbeddedBrowserWebView.@)
 */
BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    TRACE("(%p, %lu, %p)\n", instance, reason, reserved);

    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(instance);
        break;
    }
    return TRUE;
}
