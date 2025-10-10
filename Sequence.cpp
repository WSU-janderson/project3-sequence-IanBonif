/*Ian Bonifas
 *
 *
 */


#include "Sequence.h"



//sequence that makes empty list or list of sz amount of items
Sequence::Sequence(size_t sz) {
if (sz==0) {
    SequenceNode* head = nullptr;
    SequenceNode* tail = nullptr;
    size_t sz = 0;
}else {
    for (size_t i=0;i<sz;i++) {
        if (i==0) {
            SequenceNode node;
            node.next=nullptr;
            node.prev=nullptr;
        }

    }
}
}

