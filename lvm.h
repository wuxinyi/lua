/*
** $Id: lvm.h,v 1.45 2002/08/05 17:36:24 roberto Exp roberto $
** Lua virtual machine
** See Copyright Notice in lua.h
*/

#ifndef lvm_h
#define lvm_h


#include "ldo.h"
#include "lobject.h"
#include "ltm.h"


#define tostring(L,o) ((ttype(o) == LUA_TSTRING) || (luaV_tostring(L, o)))

#define tonumber(o,n)	(ttype(o) == LUA_TNUMBER || \
                         (((o) = luaV_tonumber(o,n)) != NULL))

#define equalobj(L,o1,o2) \
	(ttype(o1) == ttype(o2) && luaV_equalval(L, o1, o2))


int luaV_lessthan (lua_State *L, const TObject *l, const TObject *r);
int luaV_equalval (lua_State *L, const TObject *t1, const TObject *t2);
const TObject *luaV_tonumber (const TObject *obj, TObject *n);
int luaV_tostring (lua_State *L, TObject *obj);
const TObject *luaV_gettable (lua_State *L, const TObject *t, TObject *key,
                              int loop);
void luaV_settable (lua_State *L, const TObject *t, TObject *key, StkId val);
StkId luaV_execute (lua_State *L);
void luaV_concat (lua_State *L, int total, int last);

#endif
