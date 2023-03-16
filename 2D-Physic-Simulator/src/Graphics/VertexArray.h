#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
namespace SimulatorCore {
	class VertexArray {
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
		void bind() const;
		void unbind() const;

	private:
		unsigned int m_rendererID;

	};
}


