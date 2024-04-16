/*
Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
  ****************************************************************
  #include<unordered_map>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node* temp=firstHead;
    Node* temp2=secondHead;
    unordered_map<Node*,int> map;
    while(temp!=NULL){
            map[temp]++;
            temp=temp->next;
    }
    while(temp2!=NULL){
        if(map.find(temp2)!=map.end()){
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL;
}

*/