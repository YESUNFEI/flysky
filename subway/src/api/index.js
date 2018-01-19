import axios from 'axios'

/* common */
let common = ({ baseURL = window.domain, method = 'get', url, data }) => {
  return new Promise((resolve, reject) => {
    let opt = { baseURL, url, method }
    method === 'get' ? opt.params = data : opt.data = data
    axios(opt).then((res) => {
      res.data.success ? resolve(res.data) : reject(res.data)
    }).catch(err => {
      reject(err)
    })
  })
}
// export const wechatJsConfig = data => {
//   return common({
//     baseURL: `//unibase.zjzwfw.gov.cn:${window.weixinPort}`,
//     // baseURL: 'http://120.26.168.214:8088',workGuide
//     url: '/app_api/invitation/weixing',
//     data
//   })
// }
// import { wechatJsConfig } from '@/api'
