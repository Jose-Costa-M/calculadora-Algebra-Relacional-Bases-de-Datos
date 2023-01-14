//librerias
#include <bits/stdc++.h>
#include <stdio_ext.h> //para _fpurge(stdin); 
using namespace std;

#define _io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define lambda "\0"
#define vt vector
#define str string 
#define fi first
#define se second
#define pb push_back
#define popb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define szi(x) (int)(x).size()
#define szl(x) (lli)(x).size()
 
#define all(v) (v).begin(), (v).end()
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define gauss(n) (n*(n+1)/2)
 
#define each(x,a) for(auto &x: a)
 
#define forM(i,a,b,t,s) for(t i = t(a); i < t(b); i+=s)
#define forMe(i,a,b,t,s) for(t i = t(a); i <= t(b); i+=s)
 
#define forr(i,a) for(int i = (a)-1; i >= 0; i--)
#define forra(i,a,b) for(int i = (b)-1; i >= a; i--)
#define fori(i,b) forM(i,0,b,int,1)
#define forie(i,b) forMe(i,0,b,int,1)
#define forl(i,b) forM(i,0,b,lli,1)
#define forle(i,b) forMe(i,0,b,lli,1)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)<0?-(x):(x))
#define sgn(x) ((x)<0?-1:((x)>0?1:0))
#define sq(x) ((x)*(x))
#define cb(x) ((x)*(x)*(x))


 
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
typedef pair<ld, ld> pdd;
typedef set<string> alfabeto;
typedef set<string> prefijo;
typedef set<string> sufijo;
typedef set<string> lenguaje;
typedef vt<int> vi;
typedef vt<vi> vvi;
typedef vt<pii> vpi;
typedef vt<ll> vll;
typedef vt<lli> vli;
typedef complex<ld> cd;
typedef unordered_multiset<string> cadena_validar;
 


void menu(); 
bool automataStack(string cadena);




//funciones
void menu();
int menuTipoDatos();
void selectionOption(int opcion);
bool flagisvalidType(string dato,string tipoDato);