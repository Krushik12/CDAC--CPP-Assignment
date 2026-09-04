//Question 2 — Game Asset Manager
//Part B — shared_ptr : Shared Shader Ownership

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Shader
{
private:
    string name;
    string type;

public:
    // Parameterized Constructor
    Shader(string n, string t)
        : name(n), type(t)
    {
        cout << "[Shader Compiled]" << endl;
    }

    // Destructor
    ~Shader()
    {
        cout << "[Shader Destroyed]" << endl;
    }

    // Return reference count
    int getReferenceCount(const shared_ptr<Shader>& shader)
    {
        return shader.use_count();
    }
};

int main()
{
    // 1. Create Shader using make_shared
    auto shader = make_shared<Shader>("main_vert", "vertex");

    cout << "Ref count: " << shader.use_count() << endl;
    // 1

    {
        // 2. Renderer shares ownership
        auto rendererRef = shader;

        cout << "Ref count: " << shader.use_count() << endl;
        // 2

        // Editor shares ownership
        auto editorRef = shader;

        cout << "Ref count: " << shader.use_count() << endl;
        // 3
    }

    // rendererRef and editorRef are destroyed here

    cout << "Ref count: " << shader.use_count() << endl;
    // 1

    return 0;
}