template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    this->length = 0;                 
    head = nullptr;                   

    if (copyObj.head == nullptr) {    
        return;                       
    }                                 

    Node* src = copyObj.head;         
    head = new Node(src->value);      
    this->length = 1;                 

    Node* dest = head;                
    src = src->next;                  

    while (src != nullptr) {          
        dest->next = new Node(src->value); 
        dest = dest->next;            
        src = src->next;              
        this->length++;               
    }                                 
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
    if (position < 0 || position > this->length) {    
        throw string("insert: error, position out of bounds"); 
    }                                                  

    Node* n = new Node(elem);                          

    if (position == 0) {                               
        n->next = head;                                
        head = n;                                      
    }                                                  
    else {                                             
        Node* curr = head;                             
        for (int i = 0; i < position - 1; i++) {       
            curr = curr->next;                         
        }                                              

        n->next = curr->next;                          
        curr->next = n;                                
    }                                                  

    this->length++;    

}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
    if (position < 0 || position >= this->length) {   
        throw string("remove: error, position out of bounds"); 
    }                                                  

    if (position == 0) {                               
        Node* temp = head;                             
        head = head->next;                             
        delete temp;                                   
    }                                                  
    else {                                             
        Node* curr = head;                             
        for (int i = 0; i < position - 1; i++) {       
            curr = curr->next;                         
        }                                              

        Node* temp = curr->next;                       
        curr->next = temp->next;                       
        delete temp;                                   
    }                                                  

    this->length--;     

}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
