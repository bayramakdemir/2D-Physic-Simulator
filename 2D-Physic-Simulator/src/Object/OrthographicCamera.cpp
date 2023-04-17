#include "OrthographicCamera.h"
#include "glm/gtx/transform.hpp"

namespace Simulator {
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top) 
	:m_projectionMatrix(glm::ortho(left,right,bottom, top, -1.0f, 1.0f)), m_viewMatrix(1.0f) {
		m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
	}

	void OrthographicCamera::setProjection(float left, float right, float bottom, float top) {
		m_projectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
	}

	void OrthographicCamera::recalculateViewMatrix() {
	
		glm::mat4 TransformComponent = glm::translate(glm::mat4(1.0f), m_position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation), glm::vec3(0, 0, 1));

		m_viewMatrix = glm::inverse(TransformComponent);
		m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
	}

}