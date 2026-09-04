//Question 2 — Game Asset Manager
//Part A — unique_ptr : Exclusive Asset Ownership


#include<iostream>
using namespace std;
#include<string>
#include<memory>
class Texture{
    string name;
    int width;
    int height;
    
    public:
    Texture()
    : name(""), width(0), height(0)
        {
            cout << "[Default Constructor]" << endl;
        }
    Texture(string n, int w, int h)
    : name(n), width(w), height(h)
    {
        cout << "[Texture Loaded]" << endl;
    }
    ~Texture(){
        cout << "[Texture Released]" << endl;
    }

    void display()const {
        cout << "Texture: " << name << endl;
        cout << "Dimensions: " << width << " x " << height << endl;
    }




};

int main()
{
    // 1. Create Texture using make_unique
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    // 2. Call display() through unique_ptr
    tex1->display();

    // 3. Attempt to copy unique_ptr
    // unique_ptr<Texture> tex2 = tex1;
    // ERROR: unique_ptr cannot be copied because it has exclusive ownership.

    // 4. Transfer ownership using move()
    unique_ptr<Texture> tex2 = move(tex1);

    // Check whether tex1 is nullptr
    cout << "tex1 is null: "
         << (tex1 == nullptr ? "YES" : "NO") << endl;

    // tex2 now owns the Texture
    tex2->display();

    // 5. tex2 goes out of scope at the end of main()
    // Destructor is automatically called.

    return 0;
}