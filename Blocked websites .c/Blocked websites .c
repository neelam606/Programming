#include "bits/stdc++.h"
using namespace std;
const int N=2e5+10;
string a[N];
vector<int> node[N];
char c[N];
vector<char> v;
pair<string,char> b[N];
int zo[N];
char mn[N];
int vis[N];
int w=0;
int o=0;
vector<char> stri[N];
vector<int> ch[N];
void dfs(int u)
{
  vis[u]=1;
  if((ch[u].size()>1)||(vis[ch[u][0]]==0))
  {
    for(int i=0;i<ch[u].size();i++)
    {
      if(vis[ch[u][i]]==0)
      {
        vis[ch[u][i]]=1;
        v.push_back(mn[ch[u][i]]);
        if(zo[ch[u][i]]==0)
        {
          for(int j=0;j<v.size();j++)
          {
            stri[w].push_back(v[j]);
          }
          w++;
        }
        else
        {
          dfs(ch[u][i]);
        }
      v.pop_back();
      }
    }
  }
  else
  {
    if(zo[u]==1)
    {
      o=1;
    }
  }
}
int main()
{
  int n,j;
  cin>>n;
  for(int loke=0;loke<n;loke++)
  {
    cin>>c[loke]>>a[loke];
    b[loke]=make_pair(a[loke],c[loke]);
  }
  sort(a,a+n);
  sort(b,b+n);
  int ct=1;
  int last=0;
  int last1=0;
   int ct1 =0;
  for(int i=0;i<n;i++)
  {
      if(b[i].second=='+')
      {
          ct1++;
      }
      else if(i<(n-1))
      {
          int ct111=0;
          if((b[i+1].second=='+')&&(a[i+1].length()>=a[i].length()))
          {
              for(int l1=0;l1<a[i].length();l1++)
              {
                  if(a[i+1][l1]!=a[i][l1])
                  {
                      ct111++;
                      break;
                  }
              }
              if(ct111==0)
              {
                  o=1;
              }
          }
          
      }
  }
if(ct1<n)
{
  for(int i=0;i<n;i++)
  {
   if(last1!=0)
    {
    for(j=0;j<a[i].length();j++)
    {
      if((b[i].second=='-'))
      {
         if (j<=a[last].length())
        {
          if((a[i][j]!=a[last][j])&&(j!=0))
          {
            ch[ct].push_back(node[last][j-1]);
            node[i].push_back(ct);
            ch[node[last][j-1]].push_back(node[i][j]);
            mn[ct]=a[i][j];
            ct++;
            break;
          }
          else if((j==0)&&(a[i][j]!=a[last][j]))
          {
            node[i].push_back(ct);
            mn[ct]=a[i][j];
            ct++;
            break;
          }
          else
          {
            node[i].push_back(node[last][j]);
          }
        }
        else
        {
          break;
        }
      }
      else
      {
        break;
      }
 
    }
    }
    if((last1==0)&&(b[i].second=='-'))
    {
        node[i].push_back(ct);
        mn[ct]=a[i][j];
        ct++;
        last1=1;
    }
    if((j==0)&&(b[i].second=='-'))
    {
      ch[0].push_back(ct-1);
      ch[ct-1].push_back(0);
      mn[0]='/';
    }
    for(int k=j+1;k<a[i].length();k++)
    {
      if((b[i].second=='-'))
      {
        ch[ct].push_back(node[i][k-1]);
        ch[node[i][k-1]].push_back(ct);
        node[i].push_back(ct);
        mn[ct]=a[i][k];
        ct++;
      }
      else
      {
        break;
      }
    }
    if(b[i].second=='-')
    {
        last=i;
    }
    j=0;
  }
  for(int i=0;i<n;i++)
  {
    if(b[i].second=='+')
    {
      if(i==0)
      {
        if(b[i+1].second=='-')
        {
          if(a[i].length()>=a[i+1].length())
          {
            for(j=0;j<a[i+1].length();j++)
            {
              if(a[i+1][j]==a[i][j])
              {
                 zo[node[i+1][j]]=1;
              }
              else
              {
                break;
              }
            }
          }
          else
          {
            for(int j=0;j<a[i].length();j++)
            {
              if(a[i+1][j]==a[i][j])
              {
                zo[ node[i+1][j] ]=1;
              }
              else
              {
              break;
              }
            }
          }
        }
        else
        {
 
        }
      }
      else if(i+1==n)
      {
        if(b[i-1].second=='-')
        {
          if(a[i].length()>=a[i-1].length())
          {
            for(j=0;j<a[i-1].length();j++)
            {
              if(a[i-1][j]==a[i][j])
              {
                zo[node[i-1][j]]=1;
              }
              else
              {
              break;
              }
            }
          }
          else
          {
            for(int j=0;j<a[i].length();j++)
            {
              if(a[i-1][j]==a[i][j])
              {
                zo[node[i-1][j]]=1;
              }
              else
              {
                break;
              }
            }
          }
        }
        else
        {
 
        }
      }
      else
      {
        if(b[i+1].second=='-')
        {
          if(a[i].length()>=a[i+1].length())
          {
            for(j=0;j<a[i+1].length();j++)
            {
              if(a[i+1][j]==a[i][j])
              {
                zo[node[i+1][j]]=1;
              }
              else
              {
                break;
              }
            }
          }
          else
          {
            for(int j=0;j<a[i].length();j++)
            {
              if(a[i+1][j]==a[i][j])
              {
                zo[node[i+1][j]]=1;
              }
              else
              {
                break;
              }
            }
          }
        }
        else
        {
 
        }
 
        if(b[i-1].second=='-')
        {
          if(a[i].length()>=a[i-1].length())
          {
            for(j=0;j<a[i-1].length();j++)
            {
              if(a[i-1][j]==a[i][j])
              {
                zo[node[i-1][j]]=1;
              }
              else
              {
                break;
              }
            }
          }
          else
          {
            for(int j=0;j<a[i].length();j++)
            {
              if(a[i-1][j]==a[i][j])
              {
                zo[node[i-1][j]]=1;
              }
              else
              {
                break;
              }
            }
          }
        }
        else
        {
 
        }
      }
    }
  }
  dfs(0);
}
  if(ct1==n)
  {
      o=1;
  }
  else
  {
 
  }
  if(o==0)
  {
    
    cout<<w<<'\n';
    for(int i=0;i<w;i++)
    {
      for(int j=0;j<stri[i].size();j++)
      {
        cout<<stri[i][j];
      }
      cout<<'\n';
    }
  }
  else
  {
      cout<<"-1\n";
  }
  return 0;
}
 
