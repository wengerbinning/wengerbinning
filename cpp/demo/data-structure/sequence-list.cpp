/* Array is a line data structure
 * 
 *
 */

#include <iostream>

using namespace std;

// Sequence list template class.
template <class T>
class Slist {
  private:
    T *data[];
    unsigned int count;
  public:
    Slist();
    int insert(int idx, T &element);
    T  &delete(int idx);
    ~Slist();
}




int main(int argc, const char **argv) {
    

    return 0;
}
