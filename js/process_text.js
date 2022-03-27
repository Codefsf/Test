const os = require('os');
const fs = require('fs');
const readline = require('readline');

function process_text(filename)
{
    if(filename === undefined)
    {
        return;
    }

    console.log('intput filename:' + filename);
    // fs.readFile(filename, 'utf8', function(err, data){
    //     if(err)
    //     {
    //         console.error('err:' + err);
    //         return;
    //     }

    //     console.log(data);
    // })

    const rl = readline.createInterface(
        process.stdin,
        process.stdout
    );

    rl.on('line', (line)=>{
        console.log(line);
    });

    rl.on('resume', ()=>{
        console.log('resume')
    });
}

process_text("timezone.txt");
