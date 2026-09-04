//Question 2 — Game Asset Manager
//Part C — weak_ptr : Non-Owning Observer

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class AudioClip
{
private:
    string name;
    double duration;

public:
    // Constructor
    AudioClip(string n, double d)
        : name(n), duration(d)
    {
        cout << "[AudioClip Loaded]" << endl;
    }

    // Destructor
    ~AudioClip()
    {
        cout << "[AudioClip Released]" << endl;
    }

    string getName() const
    {
        return name;
    }
};

int main()
{
    // 1. Create AudioClip using make_shared
    auto audio = make_shared<AudioClip>("explosion", 3.5);

    // 2. Create weak_ptr observer
    weak_ptr<AudioClip> observer = audio;

    // 3. Try to access the AudioClip using lock()
    if (auto clip = observer.lock())
    {
        cout << "Clip alive: " << clip->getName() << endl;
    }

    // 4. Reset shared_ptr - simulating unload
    audio.reset();

    // 5. Check whether AudioClip is still alive
    // Using lock again it show audioclip doesn't exist (empty)
    if (observer.expired())
    {
        cout << "Clip already unloaded." << endl;
    }

    return 0;
}