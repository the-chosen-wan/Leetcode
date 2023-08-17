const axios = require("axios")

const promisify = (url)=>{
    return new Promise((resolve,reject)=>{
        axios({url : url}).then((data)=>{
            resolve(data.data.data)
        })
    })
}

async function ans(keyword, region){
    
}