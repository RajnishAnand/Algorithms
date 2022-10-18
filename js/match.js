const a = ["hellz","hella thewe","lol","opps!","prasant","arnav","happi"];

/** convert to number
 * @param str string
 */
function toNumber(str){
  let r = "";
  for(let i=0;i<str.length;i++)
    r+=str.charCodeAt(i);
  return parseInt(r);
}

function search(str){
  strLen=str.length;
  str=toNumber(str.toLowerCase());
  //console.log("start:",str );
  return a.reduce((p,c)=>{
    // console.log(`Previous & Previous diff: ${p} \nCurrent: ${c} \nCurrentBinary: ${toNumber(c)}\n`);
    const diff = Math.abs(str-toNumber(c.substring(0,strLen)));
    return diff>p[1]?p:[c,diff];
  },[])
}

const print = search("Happy");

console.log(print)
