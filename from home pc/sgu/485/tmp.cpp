      for(int pre=-1;rht>=n+lev && p[rht]>lb;--rht)
	if(p[rht]<ub && !vis[rht] && pre!=p[rht])
	  {
	    pre=p[rht];
	    vis[rht]=true;
	    int llft=(llf1==rht?llf2:llf1);
	    int llb=-1,uub=INF;
	    if(p[rht]>p[llft])
	      uub=p[lft]-p[lev];
	    else if(p[rht]<p[llft])
	      {
		z.push_back(make_pair(p[lft]-p[lev],p[rht]));
		int i=z.size()-1;
		for(;i>=0 && z[i].second<p[llft];--i)
		  ;
		++i;
		llb=z[i].first;
	      }
	      //llb=max(lb,p[lft]-p[lev]);
	    //cout<<"!"<<(p[lft]-p[lev])<<' '<<p[lft]<<' '<<p[lev]<<' '<<lev<<endl;
	    dfs(lev-1,llft,rht-1,llb,uub,num+(p[lft]-p[lev])*p[rht]);
	    vis[rht]=false;
	    if(p[rht]<p[llft])
	      z.pop_back();
	  }
8447252
