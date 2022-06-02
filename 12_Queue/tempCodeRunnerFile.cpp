int tour(petrolPump p[],int n)
    // {
    //    //Your code here
    //    queue<int> q;
    //    int tot=0;
    //    for(int i=0;i<n;i++){
    //        int diff=p[i].petrol-p[i].distance;
    //        tot += diff;
    //        if(diff>=0) q.push(i);
    //    }
    //    if(tot<0) return -1;
       
    //   while(!q.empty()){
    //       int i=q.front();
    //       int j=(i+1)%n,fuel=p[i].petrol-p[i].distance;
    //       while(fuel>=0){
    //           if(j==i) return i;
    //           fuel += (p[j].petrol-p[j].distance);
    //           j=(j+1)%n;
    //       }
    //       q.pop();
    //   }
    //    return -1;
    // }