#include "pch.h"
#include "Peach/Layer.h"

namespace Peach
{
    Layer::Layer(const std::string &debugName)
        : m_DebugName(debugName) {}
    
    Layer::~Layer()
    {
        
    }
}