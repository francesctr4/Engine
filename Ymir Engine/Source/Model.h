#pragma once

#include <string>

#include "Mesh.h"

#include "External/Assimp/include/cimport.h"
#include "External/Assimp/include/scene.h"
#include "External/Assimp/include/postprocess.h"

#include "JsonFile.h"

#pragma comment (lib, "Source/External/Assimp/libx86/assimp.lib")

class GameObject;

struct NodeTransform {
  
    float3 translation;
    float3 rotation;
    float3 scale;

};

class Model {

public:

    Model();
    Model(const std::string& path);

    virtual ~Model();

    void LoadModel(const std::string& path);
    void DrawModel();

private:

    void ProcessNode(aiNode* node, const aiScene* scene, GameObject* parentGO);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene, GameObject* linkGO, NodeTransform* transform);

public:

    // Model Data

    std::string name;
    std::string path;

    std::vector<Mesh> meshes;
    std::string directory;

    GameObject* modelGO;

    // Vector of already loaded textures

    //std::vector<Texture> loadedTextures;

    std::vector<int> embeddedMeshesUID;

};