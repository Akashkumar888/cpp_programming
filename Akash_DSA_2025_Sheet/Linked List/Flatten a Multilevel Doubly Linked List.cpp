
class Solution {
public:
    Node* flatten(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* a = temp->next;   // save next

        if (temp->child != NULL) {
            Node* c = temp->child;
            temp->child = NULL;

            c = flatten(c);     // flatten child list

            temp->next = c;     // attach child after temp
            c->prev = temp;

            // go to tail of child list
            while (c->next != NULL) {
                c = c->next;
            }

            c->next = a;        // attach original next
            if (a) a->prev = c;
        }
        temp = a;               // continue with original next
    }
    return head;
}
};


// ✅ 2️⃣ Second Solution (DFS + Tail Return) — BEST Recursive Version
// This one fixes the inefficiency.
// Key Idea
// 👉 Every recursive call returns the tail of the flattened list
// So no need to scan using while(c->next).


class Solution {
public:
    Node* dfs(Node* head) {
        Node* curr = head;
        Node* last = head;
        while (curr) {
            Node* nextNode = curr->next;
            // If child exists
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);

                // connect curr -> child
                curr->next = childHead;
                childHead->prev = curr;

                // connect childTail -> nextNode
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                curr->child = NULL;   // important
                last = childTail;
            } 
            else {
                last = curr;
            }
            curr = nextNode;
        }
        return last;
    }
    Node* flatten(Node* head) {
        if (!head) return NULL;
        dfs(head);
        return head;
    }
};


// ✅ 3️⃣ STACK-Based (Iterative) Solution (NO recursion)
// This is interview-favorite 🔥
// Idea
// Use stack to remember next nodes
// Always go depth-first
// Child first, then next

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;

        stack<Node*> st;
        Node* curr = head;

        while (curr) {
            if (curr->child) {
                if (curr->next)
                    st.push(curr->next);

                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            else if (!curr->next && !st.empty()) {
                curr->next = st.top();
                st.top()->prev = curr;
                st.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};
