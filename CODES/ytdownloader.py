import youtube_dl

links = ['https://www.youtube.com/watch?v=QoMKpPyPcrI']

ydl_opts = {
    'format' : 'bestvideo+bestaudio',
    'writesubtitles' : 'writesubtitles',
    'outtmpl' : '<path>' + '/%(title)s.%(ext)s'
}

with youtube_dl.YoutubeDL(ydl_opts) as ydl:
    ydl.download(links)
