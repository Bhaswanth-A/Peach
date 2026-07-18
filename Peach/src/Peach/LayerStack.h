#pragma once

#include "Peach/core.h"
#include "Peach/Layer.h"

#include <vector>

namespace Peach
{
    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        // A "Layer" represents a distinct, self-contained piece of the application's
        // update/render/event logic — e.g. the game world, a debug console, or a
        // separate game state (menu, pause screen). Layers are stacked and processed
        // in order: updated/rendered front-to-back, but given events back-to-front,
        // so layers drawn on top get the first chance to consume input (e.g. a UI
        // panel should intercept a mouse click before it reaches the 3D scene below it).
        //
        // An "Overlay" is just a Layer that always sits on top of every regular layer,
        // regardless of insertion order — typically used for things like a debug/UI
        // overlay (e.g. ImGui) that should always render last and receive events first.
        // Regular layers are inserted up to the m_LayerInsert boundary; overlays are
        // always appended after that boundary, at the very end of the stack.

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *overlay);
        void PopLayer(Layer *layer);
        void PopOverlay(Layer *overlay);

        std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer *>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer *> m_Layers;
        std::vector<Layer *>::iterator m_LayerInsert;
    };
}