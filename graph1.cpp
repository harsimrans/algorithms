#include<iostream>
#include<string>

using namespace std;

class Node{
  private:
    string name;
    int id;
  public:
//    Node(int id, string name)
//    {
//      setId(id);
//      setName(name);
//    }
    
    void setId(int Id)
    {
      id = Id;
    }
    
    int getId()
    {
      return id;
    }
    
    string getName()
    {
      return name;
    }
      
    void setName(string nodeName)
    {
      name = nodeName;
    }  
};

class Edge{
  private:
    Node src, dest;
  public:
    Edge(Node &source, Node &destination)
    {
      src = source;
      dest = destination;
    }  

};

int main()
{
//  Node foo(1, "hello");
//  cout<<"the name is : "<<foo.getName()<<" and id : "<<foo.getId()<<endl;
//  
//  Node bar(2, "apple");
//  cout<<"the name is : "<<bar.getName()<<endl;
//  
  
  return 0;
}
