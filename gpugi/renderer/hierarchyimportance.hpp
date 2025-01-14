#pragma once

#include "renderer.hpp"
#include <glhelper/screenalignedtriangle.hpp>
#include <glhelper/framebufferobject.hpp>
#include <glhelper/shaderobject.hpp>
#include "../scene/lightsampler.hpp"

namespace gl
{
	class TextureBufferView;
	class Texture2D;
}

/// Renderer that generates an importance value for each node/triangle.
class HierarchyImportance : public Renderer
{
public:
	HierarchyImportance(RendererSystem& _rendererSystem);

	std::string GetName() const override { return "HierachyImp"; }

	void SetScene(std::shared_ptr<Scene> _scene) override;
	void SetScreenSize(const gl::Texture2D& _newBackbuffer) override;
	void SetEnvironmentMap(std::shared_ptr<gl::TextureCubemap> _envMap) override;

	/// Returns hierarchy importance for possible use in other systems.
	///
	/// Contains a float entry for all inner nodes (first) and triangles (after node entries).
	/// If no call of UpdateHierarchyNodeImportance proceeded, only the triangles have valid importance values.
	std::shared_ptr<gl::Buffer>& GetHierachyImportance() { return m_hierarchyImportance; }

	int GetNumImportanceIterations() const { return m_numImportanceIterations; }

	/// Updates the hierarchy importance of all inner nodes by propagating them from the triangles up through the tree.
	void UpdateHierarchyNodeImportance();

	void Draw() override;

	/// Internal ssbo binding points
	enum class Binding {
		HIERARCHY_IMPORTANCE = 6,	///< The hierarchy importance buffer
		SUBTREE_IMPORTANCE = 10,	///< Second importance buffer to propagate different values during importance update
		PARENT_POINTER = 11,		///< Additional hierarchy information (parent pointers per node)
		SGGX_NDF = 7,				///< An NDF for each node stored in SGGX basis
		HIERARCHY_MATERIAL = 8,		///< Averaged material parameters from scene
		DIFFUSE_ILLUM_CACHE = 9,	///< RGB+Count for each node in the hierarchy to reuse previous samples.
	};

private:
	gl::ShaderObject m_hierarchyImpAcquisitionShader;
	gl::ShaderObject m_hierarchyImpPropagationInitShader;
	gl::ShaderObject m_hierarchyImpPropagationNodeShader;
	gl::ShaderObject m_hierarchyPathTracer;

	gl::UniformBufferMetaInfo m_hierarchyImportanceUBOInfo;
	std::unique_ptr<gl::Buffer> m_hierarchyImportanceUBO;
	static const ei::UVec2 m_localSizePathtracer;

	std::unique_ptr<gl::TextureBufferView> m_sceneParentPointer;
	std::unique_ptr<gl::TextureBufferView> m_sggxBufferView;
	std::unique_ptr<gl::TextureBufferView> m_hierachyImportanceView;
	std::shared_ptr<gl::Buffer> m_hierarchyImportance;
	std::shared_ptr<gl::Buffer> m_subtreeImportance;
	std::shared_ptr<gl::Buffer> m_cachedDiffuseIllumination;
	int m_numImportanceIterations;

	// Extra buffer with average material information per node
	std::shared_ptr<gl::Buffer> m_hierarchyMaterialBuffer;
	std::unique_ptr<gl::TextureBufferView> m_hierarchyMaterialBufferView;
	void ComputeHierarchyMaterials(std::shared_ptr<Scene> _scene);

	void RecompileShaders(const std::string& _additionalDefines);
};

