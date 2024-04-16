/*

*****************************************************************************************
node *findMiddleNode(node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  node *slow = head;
  node *fast = head->next; // head->next because we want slow to point to the
                           // first element/middle in the even length case

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// merge linked list function
node *merge(node *list1Head, node *list2Head) {
  node *dummyNode = new node(-1); // can be any value
  node *temp = dummyNode;

  while (list1Head != NULL && list2Head != NULL) {
    if (list1Head->data <= list2Head->data) {
      temp->next = list1Head;
      temp = list1Head;
      list1Head = list1Head->next;
    } else {
      temp->next = list2Head;
      temp = list2Head;
      list2Head = list2Head->next;
    }
  }

  // if list1 still has elements left
  while (list1Head != NULL) {
    temp->next = list1Head;
    temp = list1Head;
    list1Head = list1Head->next;
  }

  // if list2 still has elements left
  while (list2Head != NULL) {
    temp->next = list2Head;
    temp = list2Head;
    list2Head = list2Head->next;
  }
  return dummyNode->next;
}

// MergeSort recursive
node *mergeSort(node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  node *mid = findMiddleNode(head);
  node *leftHead = head;
  node *rightHead = mid->next;
  mid->next = NULL; // Disconnect the left and right halves

  leftHead = mergeSort(leftHead);
  rightHead = mergeSort(rightHead);
  return merge(leftHead, rightHead);
}
*/