const txt = "hello there is any way you have a testing and it will look for let x in this is an illusion that is not the mission so instead I have been working in desktop and it will return on my money 💰💰💰💰 in my mind if we have some other time i just a wrapper on my way back in town so i requested for let x in a channel copy webhook URL https connection to use the form below this category all categories";

function intoChunks(text, split){
  let lastSplitIndex = 0;
  let lastSplitLength = split.min;
  const chunks = [];

  o:for(let i=0;lastSplitIndex<text.length;i+=lastSplitLength){
    // if(lastSplitIndex )
    // console.log(lastSplitIndex,text.length)
    for(let j = split.min; j < split.max;j++){
      if(text[lastSplitIndex+j-1]==split.with){
        chunks.push(text.substring(
          lastSplitIndex,
          lastSplitIndex+j
        ));
        lastSplitLength=j;
        lastSplitIndex+=j;
        continue o;
      }
    }
    chunks.push(text.substring(
      lastSplitIndex,
      lastSplitIndex+split.min+1
    ))
    lastSplitIndex+=split.min+1;
    lastSplitLength=split.min;
  }

  return chunks;
}


console.log(intoChunks(txt,{min: 20, max: 40, with: " "}))
