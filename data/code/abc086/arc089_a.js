process.stdin.resume();
process.stdin.setEncoding('utf8');
var lines=[];
var reader=require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});
reader.on('line',(line)=>{
    lines.push(line);
});
reader.on('close',()=>{
    let n=parseInt(lines[0],10);
    let tuples;
    for(let i=1;i<=n;i++){
        let [t,x,y]=lines[i].split(' ').map((n)=>parseInt(n,10));
        if(i==1){
            if(t>=x+y&&t%2==(x+y)%2)continue;
            console.log("No");
            return;
        }
        let [pt,px,py]=lines[i-1].split(' ').map((n)=>parseInt(n,10));
        if(t-pt>=Math.abs(x-px)+Math.abs(y-py)&&(t-pt)%2==(Math.abs(x-px)+Math.abs(y-py))%2)continue;
        console.log("No");
        return;
    }
    console.log("Yes");
});