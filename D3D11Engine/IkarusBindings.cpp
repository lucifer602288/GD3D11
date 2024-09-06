#include "pch.h"
#include "IkarusBindings.h"
#include "Engine.h"
#include "BaseGraphicsEngine.h"
#include "BaseLineRenderer.h"
#include "GothicAPI.h"


#include "zSTRING.h"
#include "zCParser.h"

extern "C"
{
    /** Draws a red cross at the given location in the current frame
        - Position: Pointer to the vector to draw the cross at
        - Size: Size of the cross. (About 25 is the size of a human head) */
    __declspec(dllexport) void __cdecl GDX_AddPointLocator( float3* position, float size ) {
        Engine::GraphicsEngine->GetLineRenderer()->AddPointLocator( *position->toXMFLOAT3(), size, XMFLOAT4( 1, 0, 0, 1 ) );
    }

    /** Sets the fog-color to use when not in fog-zone */
    __declspec(dllexport) void __cdecl GDX_SetFogColor( DWORD color ) {
        Engine::GAPI->GetRendererState().RendererSettings.FogColorMod = float3( color );
    }

    /** Sets the global fog-density when not in fog-zone
        - Density: Very small values are needed, like 0.00004f for example. */
    __declspec(dllexport) void __cdecl GDX_SetFogDensity( float density ) {
        Engine::GAPI->GetRendererState().RendererSettings.FogGlobalDensity = density;
    }

    /** Sets the height of the fog */
    __declspec(dllexport) void __cdecl GDX_SetFogHeight( float height ) {
        Engine::GAPI->GetRendererState().RendererSettings.FogHeight = height;
    }

    /** Sets the falloff of the fog. A very small value means no falloff at all. */
    __declspec(dllexport) void __cdecl GDX_SetFogHeightFalloff( float falloff ) {
        Engine::GAPI->GetRendererState().RendererSettings.FogHeightFalloff = falloff;
    }

    /** Sets the sun color */
    __declspec(dllexport) void __cdecl GDX_SetSunColor( DWORD color ) {
        Engine::GAPI->GetRendererState().RendererSettings.SunLightColor = float3( color );
    }

    /** Sets the strength of the sun. Values above 1.0f are supported. */
    __declspec(dllexport) void __cdecl GDX_SetSunStrength( float strength ) {
        Engine::GAPI->GetRendererState().RendererSettings.SunLightStrength = strength;
    }

    /** Sets base-strength of the dynamic shadows. 0 means no dynamic shadows are not visible at all. */
    __declspec(dllexport) void __cdecl GDX_SetShadowStrength( float strength ) {
        Engine::GAPI->GetRendererState().RendererSettings.ShadowStrength = strength;
    }

    /** Sets strength of the original vertex lighting on the worldmesh for pixels which are in shadow.
        Keep in mind that these pixels will also be darkened by the ShadowStrength-Parameter*/
    __declspec(dllexport) void __cdecl GDX_SetShadowAOStrength( float strength ) {
        Engine::GAPI->GetRendererState().RendererSettings.ShadowAOStrength = strength;
    }

    /** Sets strength of the original vertex lighting on the worldmesh for pixels which are NOT in shadow */
    __declspec(dllexport) void __cdecl GDX_SetWorldAOStrength( float strength ) {
        Engine::GAPI->GetRendererState().RendererSettings.WorldAOStrength = strength;
    }

};
